import javax.swing.*;
import java.util.ArrayList;

public class Inmultire extends ComplexExpression{

    public Inmultire(ArrayList<NumarComplex> args){
        super(Operation.MULTIPLICATION, args);
    }

    @Override
    public NumarComplex executeOneOperation(NumarComplex num1, NumarComplex num2) {
        return num1.inmultire(num2);
    }
}
