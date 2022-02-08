import java.io.*;
import java.util.*;
public class file3
{
public static void main(String[] args) throws IOException {
int j=1;
char ch;
Scanner sc=new Scanner(System.in);
System.out.println("Enter File name:");
String str=sc.next();
FileInputStream f=new FileInputStream(str);
System.out.println("Content of the file is : ");
int n=f.available();
System.out.print(j+":");
for(int i=0;i<n;i++)
{   ch=(char)f.read();
   System.out.print(ch);
   if(ch=='\n' || ch=='.')
   {   System.out.print("\n" + ++j + ":");
   }
}
System.out.print("\b\b------END OF FILE--------");
f.close();
}
}
