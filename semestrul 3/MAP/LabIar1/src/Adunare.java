

import java.util.ArrayList;

public class Adunare extends ComplexExpression {

    public Adunare(ArrayList<NumarComplex> args)
    {
        super(Operation.ADDITION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex num1, NumarComplex num2) {
        return num1.adunare(num2);
    }

}