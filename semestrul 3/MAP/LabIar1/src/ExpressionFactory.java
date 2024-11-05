import java.util.ArrayList;

public class ExpressionFactory {

    private static ExpressionFactory instance = new ExpressionFactory();

    private ExpressionFactory() {}

    public static ExpressionFactory getInstance() {
        return instance;
    }

    public ComplexExpression createExpression(Operation operation, ArrayList<NumarComplex> args)
    {
        if(operation.equals(Operation.ADDITION))
        {
            ComplexExpression expr = new Adunare(args);
            return expr;
        } else
        if (operation.equals(Operation.SUBTRACTION))
        {
            ComplexExpression expr = new Scadere(args);
            return expr;
        } else
        if(operation.equals(Operation.MULTIPLICATION))
        {
            ComplexExpression expr = new Inmultire(args);
            return expr;
        } else
        if(operation.equals(Operation.DIVISION))
        {
            ComplexExpression expr = new Impartire(args);
            return expr;
        } else
        {
            throw new IllegalArgumentException("Unknown operation");
        }
    }
}
