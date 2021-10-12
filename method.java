/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package Tugas;

/**
 *
 * @author MANGGAR-LAPTOP
 */
public class nilai {
    String nama;
    int nilai;
    String grade;
    
    public nilai(){
       isiNilai("1",1,"1");
    }
    
    public void isiNilai(String x, int y, String z){
        nama =x;
        nilai =y;
        grade =z;
    }
    
    public int nilaiMhs(){
            return nilai;
        }
    public String namaMhs(){
            return nama;
        }
    public String gradeMhs(){
        return grade;
    }
}
