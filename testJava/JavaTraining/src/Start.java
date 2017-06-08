
import javax.swing.JButton;
import javax.swing.JFrame;

public class Start {

    public static void main(final String[] args) {
        final JFrame window = new JFrame("test");
        window.setSize(400, 200);
        final JButton button = new JButton("Click");
        button.setSize(100, 100);

        final Person s = new Person("Szymek", 12);

        button.addActionListener(s::shout);
        window.add(button);
        window.setVisible(true);
        /*
         * final Collection<Integer> coll = new ArrayList<Integer>(); coll.add(1); coll.add(1); coll.add(1);
         * coll.add(1); coll.add(2); coll.add(10); System.out.println(coll.stream().map(e -> { e = e + 2; e = e + 6;
         * return e; }).filter(e -> e == 9).collect(Collectors.toList()));
         */
    }
}

