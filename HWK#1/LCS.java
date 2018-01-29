/*
 * Author: Yu Xia
 * Reference: https://www.ics.uci.edu/~eppstein/161/960229.html
*/

import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class LCS {
	//	Initializing all the static variables which will be used in program
	static String txt1 = null; //Store input string
	static String txt2 = null; //Store input string
	static int[][] recordTable; // Store intermediate information
	static char[] charArray1; // Store string by each char
	static char[] charArray2; // Store string by each char
	
	public static void main(String[] args)  throws IOException{
		
		if (args.length < 1) {
			System.out.println("No file input!");
		}else {
			txt1 = loadFile(args[0]);
			txt2 = loadFile(args[1]);
		}
		
		if (txt1.length() == 0 || txt2.length() == 0)
			System.out.println(0);
		else {
			recordTable = new int[txt1.length() + 1][txt2.length() + 1];
			
			Arrays.fill(recordTable[txt1.length()], 0);
			for(int i = 0; i <= txt1.length(); i++) {
				recordTable[i][txt2.length()] = 0;
			}
			
			charArray1 = txt1.toCharArray();
			charArray2 = txt2.toCharArray();
		
		System.out.println(checkEqual(txt1.length() - 1, txt2.length() - 1));
		}
		
 	}
	
	//Function to compare two strings
	public static int checkEqual(int a, int b) {
		for(int i = txt1.length(); i >= 0; i--) {
			for(int j = txt2.length(); j >= 0; j--) {
				if(i == txt1.length() || j == txt2.length()) {	
					recordTable[i][j] = 0;
				}
				else if(charArray1[i] == charArray2[j])
					recordTable[i][j] = recordTable[i+1][j+1] + 1;
				
				else
					recordTable[i][j] = Math.max(recordTable[i+1][j], recordTable[i][j+1]);
			}
		}
		
		return recordTable[0][0];
	}
	
	//Function to load file
	public static String loadFile(String name) throws FileNotFoundException{
		String text = "";
		Scanner scan = new Scanner (new FileReader(name));
		
		while(scan.hasNext()) {
			text += scan.nextLine();
		}
		
		return text;
	}
	
}


/*		for(int[] row: recordTable) {
for(int i: row) {
	System.out.printf("%3s", i);
	
}
System.out.println("");
}
*/