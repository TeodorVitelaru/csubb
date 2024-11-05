import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ExpressionParser {
    public ComplexExpression parseExpression(String[] args) {
        ArrayList<NumarComplex> numbers = new ArrayList<>();
        Operation operation = null;
        for( String arg : args ) {
            if( arg.equals("-") ) {
                operation = Operation.SUBTRACTION;
            } else if( arg.equals("+") ) {
                operation = Operation.ADDITION;
            } else if( arg.equals("*") ) {
                operation = Operation.MULTIPLICATION;
            } else if( arg.equals("/") ) {
                operation = Operation.DIVISION;
            } else{
                numbers.add(parseComplexNumber(arg));
            }
        }

        if(operation == null || numbers.size() < 2)
        {
            throw new IllegalArgumentException("Invalid expression");
        }

        return ExpressionFactory.getInstance().createExpression(operation, numbers);
    }

    private static NumarComplex parseComplexNumber(String number) {
        number = number.replace(" ", "").replace("*i", "i");

        String regex = "([-+]?[0-9]*\\.?[0-9]+)([-+]?)([-+]?[0-9]*\\.?[0-9]+)?i?";

        Pattern pattern = Pattern.compile(regex);
        Matcher matcher = pattern.matcher(number);

        if(matcher.matches()) {
            String realS = matcher.group(1);
            double real = Double.parseDouble(matcher.group(1));
            double imag;
            String imagString = matcher.group(3);
            System.out.println(imagString);
            if(imagString == null)
            {
                imag = 0;
            } else if(imagString.equals("-i"))
            {
                imag = -1.0;
            } else if(imagString.equals("i"))
            {
                imag = 1.0;

            }
            else {
                imag = Double.parseDouble(imagString);
            }
            if(matcher.group(2).equals("-")) {
                imag = -imag;
            }
            return new NumarComplex(real, imag);
        } else {
            throw new IllegalArgumentException("Invalid expression");
        }

    }

}
