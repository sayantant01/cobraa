import java.util.Scanner;

class Customer {
	String name;
	long contactno;
	static double balance;

	Customer() {
		super();
	}

	Customer(String name, long contactno, double balance) {
		super();
		this.name = name;
		this.contactno = contactno;
		Customer.balance = balance;
	}

	void display() {
		System.out.println("Name is " + name);
		System.out.println("Contct No. is " + contactno);
		System.out.println("Balance : " + balance);
	}

}

class Withdraw extends Customer {

	void withdrawAmount(int amount) {
		if (amount <= balance) {
			balance = balance - amount;
			System.out.println("Amount withdrawn Sucessfull!!");
			System.out.println("Amount Withdrawn: " + amount);
		} else {
			System.out.println("Transaction Failed!!!");
			System.out.println("Insufficent Balance..");
		}
	}

}

class Deposit extends Customer {

	void depositAmount(int amount) {
		balance = balance + amount;
		System.out.println("Amount Deposited Sucessfully!!!");
	}

}

class Database {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter your name");
		String n = sc.next();
		System.out.println("Enter your contactno");
		long c = sc.nextLong();
		int choice;
		System.out.println("Give a Starting balance: ");
		double startingBalance = sc.nextInt();
		Customer ob = new Customer(n, c, startingBalance);

		Withdraw w = new Withdraw();
		Deposit d = new Deposit();
		while (true) {
			System.out.println();
			System.out.println("1 to Withdraw");
			System.out.println("2 to Deposit");
			System.out.println("3 to Balance Check");
			System.out.println("4 to Exit");
			choice = sc.nextInt();
			switch (choice) {
			case 1:
				System.out.println("Enter the amount: ");
				w.withdrawAmount(sc.nextInt());
				break;
			case 2:
				System.out.println("Enter the amount: ");
				d.depositAmount(sc.nextInt());
				break;
			case 3:
				ob.display();
				break;
			case 4:
				sc.close();
				return;
			default:
				System.out.println("Wrong choice, try again");
			}
		}
	}
}
