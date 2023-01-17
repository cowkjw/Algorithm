import java.util.Scanner;

public class Main {
	
	public static Scanner sc = new Scanner(System.in);
	

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		short A = sc.nextShort();
		short B = sc.nextShort();
		
		sc.close();
		
		if(A>B) {
			System.out.println(">");
		}
		else if(A<B) {
			System.out.println("<");
		}
		else 
		{
			System.out.println("==");
		}
		
	}

}
