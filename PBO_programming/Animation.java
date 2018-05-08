import javafx.animation.PathTransition;
import javafx.application.Application;
import javafx.scene.Group;
import javafx.scene.Scene;
import javafx.scene.effect.BoxBlur;
import javafx.scene.paint.Color;
import javafx.scene.shape.*;
import javafx.stage.Stage;
import javafx.util.Duration;
import javafx.animation.Interpolator;


import static javafx.animation.Animation.INDEFINITE;

public class Animation extends Application {
    @Override
    public void start(Stage primaryStage) throws Exception {
        primaryStage.setTitle("orbit");

        Group root = new Group();
        Scene scene = new Scene(root, 800, 800, Color.BLACK);
        primaryStage.setScene(scene);

        Circle sun = new Circle(50, Color.web("yellow", 1.0));
        sun.setCenterX(400);
        sun.setCenterY(400);
        sun.setEffect(new BoxBlur(10, 10, 3));

        Circle earth = new Circle(10, Color.web("blue"));
        earth.setEffect(new BoxBlur(4, 4, 3));

        root.getChildren().add(sun);
        root.getChildren().add(earth);

        Path path = new Path();
        ArcTo arcTo = new ArcTo();
        arcTo.setX(20);
        arcTo.setY(401);
        arcTo.setSweepFlag(true);
        arcTo.setLargeArcFlag(true);
        arcTo.setRadiusX(400);
        arcTo.setRadiusY(400);
        arcTo.setXAxisRotation(0);

        path.getElements().add(new MoveTo(20, 400));
        path.getElements().add(arcTo);
        path.getElements().add(new ClosePath());
        path.setVisible(false);

        PathTransition pt = new PathTransition(Duration.seconds(10), path, earth);
        pt.setInterpolator(Interpolator.LINEAR); // No acceleration/deceleration
        pt.setOrientation(PathTransition.OrientationType.ORTHOGONAL_TO_TANGENT);
        pt.setCycleCount(INDEFINITE);
        pt.play();

        primaryStage.show();
    }
}