package domain;

import domain.validators.PrietenieValidator;

import java.time.LocalDate;
import java.time.LocalDateTime;


public class Prietenie extends Entity<Tuple<Long,Long>> {

    LocalDate date;
    Long id1;
    Long id2;

    public Prietenie(Long id1, Long id2, LocalDate date) {
        this.id1 = id1;
        this.id2 = id2;
        this.date = date;
    }

    public Long getId1() {
        return id1;
    }

    public Long getId2() {
        return id2;
    }

    /**
     *
     * @return the date when the friendship was created
     */
    public LocalDate getDate() {
        return date;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Utilizator)) return false;
        Prietenie that = (Prietenie) o;
        return getId1().equals(that.getId1()) ||
                getId2().equals(that.getId2());
    }
    @Override
    public String toString() {
        return "Prietenie{" +
                "id1=" + id1 +
                ", id2=" + id2 +
                ", date=" + date +
                '}';
    }
}
