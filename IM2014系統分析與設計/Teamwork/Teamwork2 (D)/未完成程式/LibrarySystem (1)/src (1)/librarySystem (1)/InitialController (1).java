package librarySystem;

import java.util.ArrayList;
import java.awt.*;

public class InitialController {
	public static void checkUser(String ID,String password)
	{
		ArrayList<Librarian> storeLibrarian=new ArrayList<Librarian>();
		ArrayList<Member> storeMember=new ArrayList<Member>();
		Librarian checkLibrairanClass = new Librarian();
		Member checkMember = new Member();
		try
		{
		char beginChar=ID.charAt(0);
		if(beginChar=='L')
		{
			String table= new String("librarian");
			storeLibrarian=LibraryDBMgr.searchData(ID,table);
			checkLibrairanClass=storeLibrarian.get(0);
			if(password.equals(checkLibrairanClass.getlibrarianPassword()))
			{
				System.out.println("���\�n�J");
			}
			else if(checkLibrairanClass.getlibrarianPassword() == null)
			{
				System.out.println("�L���޲z��");
			}
			else
			{
				System.out.println("�n�J����");
			}
		}
		else if(beginChar=='M')
		{
			String table= new String("member");
			storeMember=LibraryDBMgr.searchData(ID,table);
			checkMember=storeMember.get(0);
			if(password.equals(checkMember.getmemberPassword()))
			{
				System.out.println("���\�n�J");
			}
			else if(checkMember.getmemberPassword() == null)
			{
				System.out.println("�L���޲z��");
			}
			else
			{
				System.out.println("�n�J����");
			}
		}
		}
		catch(Exception e)
		{
			System.out.println("�����\�j�M");
		}
	}
}
