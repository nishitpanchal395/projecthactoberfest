Java Class File
A Java class file is a file containing Java bytecode and having .class extension that can be executed by JVM. A Java class file is created by a Java compiler from .java files as a result of successful compilation. As we know that a single Java programming language source file (or we can say .java file) may contain one class or more than one class. So if a .java file has more than one class then each class will compile into a separate class files.
For Example:-
  // Compiling this Java program would
// result in multiple class files.

class Sample
{

}

// Class Declaration
class Student
{

}
// Class Declaration
class Test
{
	public static void main(String[] args)
	{
		System.out.println("Class File Structure");
	}
}
A single class file structure contains attributes that describe a class file.
Representation of Class File Structure

ClassFile 
{
     magic_number;
     minor_version;
     major_version;
     constant_pool_count;
     constant_pool[];
     access_flags;
     this_class;
     super_class;
     interfaces_count;
     interfaces[];
     fields_count;
     fields[];
     methods_count;
     methods[];
     attributes_count;
     attributes[];
}

  
