public class NumarComplex {
    double re;
    double im;
    public NumarComplex(double re, double im) {
        this.re = re;
        this.im = im;
    }
    public NumarComplex adunare(NumarComplex other) {
        NumarComplex nr = new NumarComplex(this.re + other.re, this.im + other.im);
        return nr;
    }
    public NumarComplex scadere(NumarComplex other) {
        NumarComplex nr = new NumarComplex(this.re - other.re, this.im - other.im);
        return nr;
    }
    public NumarComplex inmultire(NumarComplex other) {
        double realPart = this.re * other.re - this.im * other.im;
        double imPart = this.re * other.im + this.im * other.re;
        NumarComplex nr = new NumarComplex(realPart, imPart);
        return nr;

    }

    public NumarComplex impartire(NumarComplex other) {
        double denominator = this.re * other.re - this.im * other.im;
        double realPart = (this.re * other.re + this.im * other.im) / denominator;
        double imagPart = (this.im * other.re - this.re * other.im) / denominator;
        NumarComplex nr = new NumarComplex(realPart, imagPart);
        return nr;

    }

    public NumarComplex conjugatul(NumarComplex nr1, NumarComplex nr2) {
        NumarComplex nr = new NumarComplex(this.re, -this.im);
        return nr;
    }

    @Override
    public String toString() {
        if (im == 0) {
            return re + "";
        } else if (re == 0) {
            return im + "*i";
        } else {
            return re + (im > 0 ? "+" : "") + im + "*i";
        }
    }




}
