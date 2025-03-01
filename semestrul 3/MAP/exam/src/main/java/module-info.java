module com.example.exam {
    requires javafx.controls;
    requires javafx.fxml;
    requires javafx.web;

    requires org.controlsfx.controls;
    requires com.dlsc.formsfx;
    requires net.synedra.validatorfx;
    requires org.kordamp.ikonli.javafx;
    requires org.kordamp.bootstrapfx.core;
    requires eu.hansolo.tilesfx;
    requires com.almasb.fxgl.all;
    requires java.sql;

    opens com.example.exam to javafx.fxml;
    opens com.example.exam.controller to javafx.fxml;
    opens com.example.exam.repo to javafx.fxml;
    opens com.example.exam.service to javafx.fxml;
    opens com.example.exam.domain to javafx.base;


    exports com.example.exam;

}