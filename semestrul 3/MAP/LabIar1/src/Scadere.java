import javax.swing.*;
import java.util.ArrayList;

public class Scadere extends ComplexExpression{

   public Scadere(ArrayList<NumarComplex> args){
       super(Operation.SUBTRACTION, args);
   }

   @Override
    public NumarComplex executeOneOperation(NumarComplex num1, NumarComplex num2) {
       return num1.scadere(num2);
   }
}
