class Person {
    String name;
    int age;
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
    public void displayInfo() {
        System.out.println("Name: " + name);
        System.out.println("Age: " + age);
    }
}
public class Student {
    public static void main(String[] args) {
        Person p1 = new Person("Prakhar", 20);
        p1.displayInfo();
        Person p2 = new Person("Priyanshi", 19);
        p2.displayInfo();
    }
}
