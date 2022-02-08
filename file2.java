import java.io.*;
import java.util.*;

public class file2 {
	public static void main(String[] args)
		throws IOException
	{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter File name:");
		String str=sc.next();
		File file = new File(str);
		FileInputStream fileInputStream = new FileInputStream(file);
		InputStreamReader inputStreamReader = new InputStreamReader(fileInputStream);
		BufferedReader bufferedReader = new BufferedReader(inputStreamReader);

		String line;
		int wordCount = 0;
		int characterCount = 0;
		int paraCount = 0;
		int whiteSpaceCount = 0;
		int sentenceCount = 0;

		while ((line = bufferedReader.readLine()) != null) {
			if (line.equals("")) {
				paraCount += 1;
			}
			else {
				characterCount += line.length();
				String words[] = line.split("\\s+");
				wordCount += words.length;
				whiteSpaceCount += wordCount - 1;
				String sentence[] = line.split("[!?.:]+");
				sentenceCount += sentence.length;
			}
		}
		if (sentenceCount >= 1) {
			paraCount++;
		}
		System.out.println("Total word count = "+ wordCount);
		System.out.println("Total number of lines= "+ sentenceCount);
		System.out.println("Total number of characters = "+ (characterCount-wordCount+sentenceCount));
	}
}
