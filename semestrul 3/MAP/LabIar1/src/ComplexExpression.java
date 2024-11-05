import java.lang.reflect.Array;
import java.util.ArrayList;

public abstract class ComplexExpression {
    private Operation operation;
    private ArrayList<NumarComplex> args;

    //Constructor
    public ComplexExpression(Operation operation, ArrayList<NumarComplex> args) {
        this.operation = operation;
        this.args = args;
    }

    public abstract NumarComplex executeOneOperation(NumarComplex num1, NumarComplex num2);

    public NumarComplex execute() {
        NumarComplex result = args.get(0);
        for (int i = 1; i < args.size(); i++) {
            result = executeOneOperation(result, args.get(i));
        }
        return result;
    }




}
