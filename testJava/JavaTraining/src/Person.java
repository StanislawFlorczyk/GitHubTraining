import java.awt.event.ActionEvent;

public class Person {

    String imie;
    Integer wiek;
    private static String check = "Szymek";

    public Person(final String s, final Integer age) {
        imie = new String(s);
        wiek = age;
        System.out.println(check == s);
        System.out.println(s.equals(check));
    }

    public void shout(final ActionEvent e) {
        System.out.println("aaa");
    }
}
