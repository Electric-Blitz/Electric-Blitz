
/* Zach Kent
 * Simple Design Made w/ Shapes
 * 
 * Creates window containing 'person' made of simple shapes.
 * Assignment was an introduction to how to open a window and display an image
 * using JavaFX.
 *  
 * [Like with all assignments from college courses, some code may be adjusted
 *  so as to prevent information unrelated to code itself or to prevent being
 *  used in similar assignments by others.]
 */

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;

import javafx.scene.Group;
import javafx.scene.layout.BorderPane;
import javafx.scene.shape.Arc;
import javafx.scene.shape.Ellipse;
import javafx.scene.shape.Line;
import javafx.scene.shape.Polygon;

public class SimpleShapePerson extends Application {
    public static void main(String[] args) {
        launch(args);
    }

    @Override

    public void start(Stage primaryStage) {
        Circle head = new Circle(100, 100, 80);
        head.setStroke(Color.BLACK);
        head.setFill(Color.LIGHTBLUE);

        // **********************************************
        // Eyes
        Circle LPup = new Circle(70, 70, 10);
        Circle RPup = new Circle(130, 70, 10);

        Ellipse LEye = new Ellipse(70, 70, 20, 15);
        LEye.setFill(Color.WHITE);
        LEye.setStroke(Color.BLACK);

        Ellipse REye = new Ellipse(130, 70, 20, 15);
        REye.setFill(Color.WHITE);
        REye.setStroke(Color.BLACK);

        // ***********************************************
        // Nose
        Line nose1 = new Line(100, 85, 80, 115);
        Line nose2 = new Line(80, 115, 110, 110);

        // ***********************************************
        // Mouth
        Arc mouth = new Arc(100, 130, 40, 20, 180, 180);
        Line upperLip = new Line(60, 130, 140, 130);

        mouth.setFill(Color.WHITE);
        mouth.setStroke(Color.RED);
        upperLip.setStroke(Color.RED);

        // ***********************************************
        // Group Up
        Group face = new Group();
        face.getChildren().addAll(head, LEye, REye, LPup, RPup, nose1, nose2, mouth,
                upperLip);

        // ***********************************************
        // Neck
        Polygon neck = new Polygon();

        neck.getPoints().addAll(80.0, 150.0, 120.0, 150.0, 120.0, 210.0, 80.0, 210.0);

        neck.setFill(Color.LIGHTBLUE);
        neck.setStroke(Color.BLACK);

        // ***********************************************
        // Body
        Polygon body = new Polygon();

        body.getPoints().addAll(18.0, 200.0, 182.0, 200.0, 150.0, 410.0, 50.0, 410.0);

        body.setFill(Color.LIGHTBLUE);
        body.setStroke(Color.BLACK);

        // ***********************************************
        // Legs
        Polygon legBlock = new Polygon();

        legBlock.getPoints().addAll(50.0, 410.0, 150.0, 410.0, 140.0, 600.0, 60.0, 600.0);

        legBlock.setFill(Color.LIGHTBLUE);
        legBlock.setStroke(Color.BLACK);

        Line leg = new Line(100, 435, 100, 600);

        Group legs = new Group();
        legs.getChildren().addAll(legBlock, leg);

        // ***********************************************
        // Clothes
        Polygon lJacket = new Polygon();
        lJacket.getPoints().addAll(18.0, 200.0, 77.0, 200.0, 77.0, 410.0, 50.0, 410.0);
        lJacket.setFill(Color.DARKGRAY);
        lJacket.setStroke(Color.BLACK);

        Polygon rJacket = new Polygon();
        rJacket.getPoints().addAll(182.0, 200.0, 123.0, 200.0, 123.0, 410.0, 150.0, 410.0);
        rJacket.setFill(Color.DARKGRAY);
        rJacket.setStroke(Color.BLACK);

        Polygon jeans = new Polygon();
        jeans.getPoints().addAll(50.0, 410.0, 150.0, 410.0, 140.5, 586.0, 59.5, 586.0);
        jeans.setFill(Color.DARKBLUE);

        Polygon shoes = new Polygon();
        shoes.getPoints().addAll(59.65, 586.0, 140.5, 586.0, 140.0, 600.0, 60.0, 600.0);
        shoes.setFill(Color.WHITE);

        Arc lShoe = new Arc(80, 590, 20, 15, 0, 180);
        lShoe.setFill(Color.WHITE);
        Arc rShoe = new Arc(120, 590, 20, 15, 0, 180);
        rShoe.setFill(Color.WHITE);

        Group clothes = new Group();
        clothes.getChildren().addAll(lJacket, rJacket, jeans, shoes, lShoe, rShoe, leg);
        // ***********************************************
        // Finalize
        Group person = new Group();
        person.getChildren().addAll(neck, body, legs, clothes, face);

        Scene scene = new Scene(new BorderPane(person), 300, 620);

        primaryStage.setTitle("Simple Shape Person");
        primaryStage.setScene(scene);
        primaryStage.show();
    }
}
