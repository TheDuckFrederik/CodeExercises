public class Person {

    public String fName;
    public String lName;
    public int age;
}

//
public void main(String[] args) {
    Person person1 = new Person();
    //
    person1.fName = "Unai";
    person1.lName = "Pujol";
    person1.age = 18;
    //
    System.out.println(person1.fName);
    System.out.println(person1.lName);
    System.out.println(person1.age);
}
