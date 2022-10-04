public class Main {
    private static final long serialVersionUID = 1L;
    static final String DEFAULT_HOST = "localhost";
    static final int DEFAULT_PORT = 3331;

    public static void main(String[] args){
        String host = DEFAULT_HOST;
        int port = DEFAULT_PORT;
        Client client;
        MainWindow window;

        try {
            client = new Client(host, port);
            window = new MainWindow(client);
        } catch (Exception e) {
            System.out.println("Could not connect to the server.");
        }
    }
}
