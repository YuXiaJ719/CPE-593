/*
 * Author: Yu Xia
 * Reference: https://www.geeksforgeeks.org/dynamic-programming-set-5-edit-distance/
*/
import java.io.*;
import java.util.Arrays;
import java.util.Scanner;
import java.util.Collections;

public class EditDist{

	static int[][] recordTable;
	static String txt1;
	static String txt2;

	static public void main(String[] args) throws IOException{

		if(args.length < 1)
			System.out.println("No input file!");
		else{
			txt1 = loadFile(args[0]);
			txt2 = loadFile(args[1]);
		}

		recordTable = new int[txt1.length() + 1][txt2.length() + 1];
		System.out.println(edit(txt1.length(), txt2.length()));
	}


	public static int edit(int a, int b){

		for(int i = 0; i<=a; i++){
			for(int j = 0; j<=b; j++){
				if(i == 0)
					recordTable[i][j] = j;
				else if(j == 0)
					recordTable[i][j] = i;
				else if(txt1.charAt(i - 1) == txt2.charAt(j - 1))
					recordTable[i][j] = recordTable[i - 1][j - 1];
				else
					recordTable[i][j] = 1 + min(recordTable[i-1][j], recordTable[i][j-1], recordTable[i-1][j-1]);
			}
		}	

		return recordTable[a][b];
	}

	public static int min(int a, int b, int c){
		return Math.min(Math.min(a, b), c);
	}

	public static String loadFile(String fileName) throws FileNotFoundException{
		String text = "";
		Scanner scan = new Scanner (new FileReader(fileName));

		while(scan.hasNext()) {
			text += scan.nextLine();
		}
		return text;
	}
}