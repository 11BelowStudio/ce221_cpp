public class Hello
{
    private String message;
    public Hello(String s)
    {
        message=s;
    }

    public void sayIt()
    {
        System.out.println("The message is " + message);
    }

    public static void main(String args[])
    {
        Hello h = new Hello("Hello World");
        h.sayIt();
    }
}

//supposed to output 'The message is Hello World'

