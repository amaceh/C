// import javafx.application.Application;
// import javafx.scene.Group;
// import javafx.scene.Scene;
// import javafx.scene.shape.Polygon;
// import javafx.stage.Stage;


// public class Main extends Application {

//   @Override
//   public void start(Stage stage) {
//     Group root = new Group();
//     Scene scene = new Scene(root, 260, 300);
//     stage.setScene(scene);

//     Group g = new Group();
//     double size = 10;
//     Polygon polygon = new Polygon();
//     polygon.getPoints().addAll( new Double[]
//         {
//             5.0*size, 0.1*size, 
//             2.0*size, 9.1*size,
//             9.7*size, 3.5*size, 
//             0.2*size, 3.5*size, 
//             7.9*size, 9.1*size

//             // 0.0, shs * 3,
//             // shs * 2, shs * 2,
//             // shs * 3, 0.0,
//             // shs * 4, shs * 2,
//             // shs * 6, shs * 3,
//             // shs * 4, shs * 4,
//             // shs * 3, shs * 6,
//             // shs * 2, shs * 4
//         } );
    
//     g.getChildren().add(polygon);
    
//     scene.setRoot(g);
//     stage.show();
//   }

//   public static void main(String[] args) {
//     launch(args);
//   }
// }

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.scene.canvas.Canvas;
import javafx.scene.canvas.GraphicsContext;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.Stage;

/**
 * ZetCode JavaFX tutorial
 *
 * This program draws a Star shape on 
 * a Canvas.
 * 
 * Author: Jan Bodnar 
 * Website: zetcode.com 
 * Last modified: June 2015
 */

public class Main extends Application {

    @Override
    public void start(Stage stage) {

        initUI(stage);
    }

    private void initUI(Stage stage) {

        Pane root = new Pane();

        Canvas canvas = new Canvas(300, 300);
        GraphicsContext gc = canvas.getGraphicsContext2D();
        drawStarShape(gc);

        root.getChildren().add(canvas);

        Scene scene = new Scene(root, 300, 250, Color.WHITESMOKE);

        stage.setTitle("Star");
        stage.setScene(scene);
        stage.show();
    }

    private void drawStarShape(GraphicsContext gc) {

        double xpoints[] = {10, 85, 110, 135, 210, 160,
            170, 110, 50, 60};
        double ypoints[] = {85, 75, 10, 75, 85, 125,
            190, 150, 190, 125};
        gc.strokePolygon(xpoints, ypoints, xpoints.length);
    }
   
    public static void main(String[] args) {
        launch(args);
    }
}
