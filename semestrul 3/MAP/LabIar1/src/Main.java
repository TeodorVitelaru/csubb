//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        String[] arguments = {"2", "+", "5-6*i", "+", "-2+1*i"};

        try {
            ExpressionParser parser = new ExpressionParser();
            ComplexExpression expression = parser.parseExpression(arguments);
            NumarComplex result = expression.execute();

            System.out.println("Rezultatul este: " + result);
        } catch (Exception e) {
            System.out.println("Eroare: " + e.getMessage());
        }
    }
}