import java.util.ArrayList;

public class Impartire extends ComplexExpression{

    public Impartire(ArrayList<NumarComplex> args){
        super(Operation.DIVISION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex num1, NumarComplex num2) {
        return num1.impartire(num2);
    }
}
