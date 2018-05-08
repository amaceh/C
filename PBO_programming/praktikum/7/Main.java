import view.ViewItems;

public class Main{
	public static void main(String[] args){
		ViewItems start = new ViewItems();
		start.view();
	}
}

/*
	compiling in ubuntu, (sh trick somehow not work in ubuntu)
	# Linux
	find -name "*.java" > sources.txt
	javac @sources.txt
	java Main

	work better
*/