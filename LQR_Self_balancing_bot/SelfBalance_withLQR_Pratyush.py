'''hello everyone!!! I am Pratyush and this is a basic controllable self balancing two wheeled turtlebot.

I have used LQR for stabilising and moving the bot. Also used controlpy to get k for negative eigen-values for given matrix A,B,R,Q.''' 



import sys
import numpy as np
import pybullet as p
import math
import time
import pybullet_data
import controlpy

M = 20
m = 5
b = 0.5
I = 0.10500391309238813
g = 9.8
l = 0.1


A=np.array([[0.0,1.,0.,0.],[0.0,0.,-m*g/M,0.],[0.0,0.,0.,1.],[0.0,0.,(m*g+M*g)/(M*l),0.]])
B=np.array([[0.],[1/M],[0.],[-1/(M*l)]])


class SelfBalanceLQR:
    
    def __init__(self):
        self.xvelMin=-.01  # x velocity
        self.xvelMax =0
        self.yMin = -0.01  # yaw
        self.yMax = 0
        self.y_ = 0
        self.Q = np.array([[ 10.,   0.,0.,0.],[  0., 1.,0.,0.],[0.,0.,10.,0.],[0.,0.,0.,100.]])
        self.R = [[0.0001]]
        self.K,self.S,self.e = controlpy.synthesis.controller_lqr(A,B,self.Q,self.R)
        
    def callback(self,np_x, angle_roll):
        y = np_x[2][0]
        u_t=-np.matmul(self.K,np_x)
        
        
        xvel = (np.matmul(A,np_x)+np.matmul(B,u_t))[0] 
        
        if y>self.yMax:
            self.yMax = y
        elif y<self.yMin:
            self.yMin =y
        if xvel>self.xvelMax:
            self.xvelMax=xvel
        elif xvel<self.xvelMin:
            self.xvelMin = xvel
            
        linear_vel = [xvel,0,0]
        angular_vel=[0,0,0]
        self.y_ = y # storing th previous value of state
        if(angle_roll<=-(math.pi)/2 and angle_roll>=(math.pi)/2):
        	return -1*u_t/100
        elif(angle_roll<(math.pi)/2 and angle_roll>-(math.pi)/2):
        	return u_t/100
        else:
        	return -4
        	
	
        


def synthesizeData_down_button(robot):

    x_coor=math.fabs(p.getBasePositionAndOrientation(robot)[0][0]) 
    angles= p.getEulerFromQuaternion(p.getBasePositionAndOrientation(robot)[1])
    ang_pitch=angles[1]
    x_vel=p.getBaseVelocity(robot)[0][0]
    
    ang_vel=p.getBaseVelocity(robot)[1][1]
    
    data=np.matrix(  [[x_coor], [x_vel], [ang_pitch+0.4], [ang_vel]] )
       
    return data, angles[2]
    

def synthesizeData_up_button(robot):

    x_coor=math.fabs(p.getBasePositionAndOrientation(robot)[0][0]) 
    angles= p.getEulerFromQuaternion(p.getBasePositionAndOrientation(robot)[1])
    ang_pitch=angles[1]
    x_vel=p.getBaseVelocity(robot)[0][0]
    #print("x_vel=",x_vel)
    ang_vel=p.getBaseVelocity(robot)[1][1]
    
    data=np.matrix(  [[x_coor], [x_vel], [ang_pitch-0.4], [ang_vel]] )
       
    return data , angles[2]
    

def synthesizeData_no_button(robot):

    x_coor=math.fabs(p.getBasePositionAndOrientation(robot)[0][0]) 
    angles= p.getEulerFromQuaternion(p.getBasePositionAndOrientation(robot)[1])
    ang_pitch=angles[1]
    x_vel=p.getBaseVelocity(robot)[0][0]
    #print("x_vel=",x_vel)
    ang_vel=p.getBaseVelocity(robot)[1][1]
    
    data=np.matrix(  [[x_coor], [x_vel], [ang_pitch], [ang_vel]] )
       
    return data , angles[2]
    


if __name__ == "__main__":
    
    id = p.connect(p.GUI)
    p.setAdditionalSearchPath(pybullet_data.getDataPath())
    plane = p.loadURDF("plane.urdf")
    p.setGravity(0, 0, -9.8)

    robot = p.loadURDF("urdf/self_balance.urdf" , [0,0,0.2])
    left_joint=0
    right_joint=1
    maxForce = 0
    balance=SelfBalanceLQR()
    
    x="no_button"
    maxForce = 0
    
    while(1):
    
        if x=="up":
        	data1,roll=synthesizeData_up_button(robot)
        	trq=balance.callback(data1,roll)
        	
        	mode = p.VELOCITY_CONTROL
        	p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq)
        	p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq)
        	
        	
        if x=="down":
        	data2,roll=synthesizeData_down_button(robot)
        	trq=balance.callback(data2,roll)
        	
        	mode = p.VELOCITY_CONTROL
        	p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq)
        	p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq)
        	
        	
        if x=="no_button":
        	data3,roll=synthesizeData_no_button(robot)
        	trq=balance.callback(data3,roll)
        	if(trq<-4.8):
        		trq=-4.8
        	elif(trq>-4.8 and trq<4.8):
        		pass
        	elif(trq>4.8):
        		trq=4.8
        	
        	mode = p.VELOCITY_CONTROL
        	p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq)
        	p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq)
        	
        
        if x=="left":
        	data4,roll=synthesizeData_no_button(robot)
        	trq=balance.callback(data4,roll)
        	if(trq<-0.9):
        		trq=-0.9
        	elif(trq>-0.9 and trq<0.9):
        		pass
        	elif(trq>0.9):
        		trq=0.9
        	mode = p.VELOCITY_CONTROL
        	maxForce=0
        	p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq-0.05)
        	p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq-0.05)
        	
        	
        if x=="right":
        	data5,roll=synthesizeData_no_button(robot)
        	trq=balance.callback(data5,roll)
        	if(trq<-0.9):
        		trq=-0.9
        	elif(trq>-0.9 and trq<0.9):
        		pass
        	elif(trq>0.9):
        		trq=0.9
        	mode = p.VELOCITY_CONTROL
        	maxForce=0
        	p.setJointMotorControl2(robot, left_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, right_joint,controlMode=mode, force=maxForce)
        	p.setJointMotorControl2(robot, left_joint , p.TORQUE_CONTROL, force = trq+0.05)
        	p.setJointMotorControl2(robot, right_joint , p.TORQUE_CONTROL, force = -trq+0.05)
        	
        	
        p.stepSimulation()
        time.sleep(0.01)
        
        
        keys = p.getKeyboardEvents()
        for k, v in keys.items():
        
        
        	if (v & p.KEY_WAS_RELEASED):
        		x="no_button"
        		
        		
        	elif (v & p.KEY_IS_DOWN):
        	
        		if (k == p.B3G_LEFT_ARROW ):
        			x="left"
        			
        			#print("left key is ressed")
        			
        			
        		elif (k == p.B3G_RIGHT_ARROW ):
        			x="right"
        			
        			#print("right key is ressed")
        			
        			
        		elif (k == p.B3G_DOWN_ARROW ):
        			x="down"
        			
       			#print("down key is pressed")
        			
        			
        		if (k == p.B3G_UP_ARROW ):
        			x="up"
        			
        			#print("up key is pressed")
        					
