import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.GridLayout;
import java.awt.event.*;

public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;

    private JTextArea txtArea;
    private JPanel btnPanel;
    private JScrollPane scrollPanel;
    private JMenu menu;
    private JMenuBar menuBar;
    private JToolBar toolBar;
    private Client client;

    public MainWindow(Client _client) {
        txtArea = new JTextArea(4, 30);
        scrollPanel = new JScrollPane(txtArea);
        btnPanel = new JPanel();
        toolBar = new JToolBar();
        menu = new JMenu();
        menuBar = new JMenuBar();
        client = _client;

        // Main frame
        btnPanel.add(new JButton(showAction));
        btnPanel.add(new JButton(playAction));
        btnPanel.add(new JButton(closeAction));

        add(btnPanel, BorderLayout.SOUTH);
        add(scrollPanel, BorderLayout.CENTER);

        // Toolbar
        toolBar.add(new JButton(showAction));
        toolBar.add(new JButton(playAction));
        toolBar.add(new JButton(closeAction));

        add(toolBar, BorderLayout.NORTH);

        // Menu
        menu.add(new JMenuItem(showAction));
        menu.add(new JMenuItem(playAction));
        menu.add(new JMenuItem(closeAction));

        menuBar.add(menu);
        setJMenuBar(menuBar);


        // Make everything visible and other default settings
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        pack();
        setVisible(true);
    }

    class ShowListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            txtArea.append("Show");
        }
    }

    class PlayListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            txtArea.append("Play");
        }
    }

    class CloseListener implements ActionListener{
        public void actionPerformed(ActionEvent e){
            System.exit(0);
        }
    }

    private AbstractAction showAction = new AbstractAction() {
        {
            putValue(Action.NAME, "Show info");
        }

        @Override public void actionPerformed( ActionEvent e ) {
            String arg = txtArea.getText();
            txtArea.append("\nShowing " + arg + " information.\n");
            txtArea.append(client.send("showMedia " + arg));
        }
    };

    private AbstractAction playAction = new AbstractAction() {
        {
            putValue(Action.NAME, "Play");
        }

        @Override public void actionPerformed( ActionEvent e ) {
            String arg = txtArea.getText();
            txtArea.append("\nPlaying " + arg + "\n");
            txtArea.append(client.send("play " + arg));        }
    };

    private AbstractAction closeAction = new AbstractAction() {
        {
            putValue(Action.NAME, "Close");
        }

        @Override public void actionPerformed( ActionEvent e ) {
            System.exit(0);
        }
};

}
