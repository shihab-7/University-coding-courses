/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Inherritance;

public class Inhr3 extends Inhr1 {
    void show2(){
        System.out.println("I am son");
    }
    public static void main(String[] args) {
        Inhr3 ob = new Inhr3();
        Inhr2 ob2 = new Inhr2();
        Inhr1 ob3 = new Inhr1();
        System.out.println(ob instanceof Inhr1);
        System.out.println(ob2 instanceof Inhr1);
    }
}
