package librarySystem;
import javax.swing.*;
public class InitialGUI {
	InitialGUI()
	{
		JFrame login=new JFrame("�n�J����");
		JButton loginButtom = new JButton("�n�J");
		JTextField ID = new JTextField(15);
		JTextField password = new JTextField(15);
		JPanel plogin= new JPanel();
		plogin.add(new JLabel("��JID"));
		plogin.add(ID);
		plogin.add(new JLabel("��J�K�X"));
		plogin.add(password);
		plogin.add(loginButtom);
		loginButtom.addActionListener(event->
		{
			InitialController.checkUser(ID.getText(),password.getText());
		});
		login.add(plogin);
		login.pack();
		login.setVisible(true);
	}
}
