package ResultPackage;

import ResultPackage.StudentPackage.RegisterStudent;
import java.util.*;

public class ResultDetails {

	
	public ArrayList<Float> grades;

	RegisterStudent rs = new RegisterStudent();

	public ResultDetails(){
		rs.getInput();
		rs.enterData();
	}

	public void enterGrade() {
		Scanner sc = new Scanner(System.in);
		
		
		
		 grades = new ArrayList<>();
		 
		 for ( int i = 0; i < rs.sems; i++ )
		{
			 int tot=0;
			System.out.println("Enter numbr of sub for sem " + (i + 1) );
			
			int n=sc.nextInt();
			for(int j=0;j<n;j++)
			{
				
		 		System.out.println("Enter crdit earned for subject " + (j + 1) );
			
				int nc=sc.nextInt();
				tot+=nc;
				
			}
			
			
			try 
			{
				float sem_grade = tot/rs.credits.get(i);
				
				if ( sem_grade > 10 )
					throw new InvalidCGPA("SGPA exceeds 10");
				else
					grades.add(sem_grade);
			}
			catch (NumberFormatException nf)
			{
				System.out.println(nf.getMessage() );
			}
			catch ( InvalidCGPA ic )
			{
				System.out.println(ic.getMessage() );
			}
		}
	}
		 
		

	public void display () {

		System.out.println("Name: " + rs.name);
		System.out.println("Branch: " + rs.branch);

		System.out.println("Semester\tCredits\tSGPA ");

		float total = 0;
		float cred_sum = 0;
		for ( int i = 0; i < rs.sems; i++ )
		{
			System.out.println( (i+1) + "\t" + rs.credits.get(i) + "\t" + grades.get(i));
			//total = total + ( grades.get(i) * rs.credits.get(i) );

			//cred_sum = cred_sum + rs.credits.get(i);
			total+=grades.get(i);
		}

		System.out.println ("Final CGPA is :" + (total/rs.sems) );

	}
	
}

class InvalidCGPA extends Exception {
	
	InvalidCGPA ( String s){
		super(s);
	}
}


/*public class TestResultDetails {
	public static void main (String args[] ) {
		

		ResultDetails rd = new ResultDetails();
		rd.enterGrade();
		rd.display();
	}
}*/

/* javac -cp . StudentPackage/RegisterStudent.java
	javac -cp . TestResultDetails.java 
	java -cp . TestResultDetails 
*/

