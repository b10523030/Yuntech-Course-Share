package librarySystem;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;
public class SendEmail {
	public static void send(Member i) {
		// Get properties object
		String from = "kencs16358@gmail.com";
		String password = "*******�n��J";
		String to = i.getmemberemail();
		String sub = "�Ϯ��]�q��";
		String msg = "" + i.getmemberName() + "�|���z�n�A�z�ثe��" + i.getnumberOfNoticeBook() + "���ѧ֭n�O��"
				+ i.getnumberOfOverdueBook() + "�w�g�O���A�кɧ��k�١A����";
		Properties props = new Properties();
		props.put("mail.smtp.host", "smtp.gmail.com");
		props.put("mail.smtp.socketFactory.port", "465");
		props.put("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");
		props.put("mail.smtp.auth", "true");
		props.put("mail.smtp.port", "465");
		// get Session
		Session session = Session.getDefaultInstance(props, new javax.mail.Authenticator() {
			protected PasswordAuthentication getPasswordAuthentication() {
				return new PasswordAuthentication(from, password);
			}
		});
		// compose message
		try {
			MimeMessage message = new MimeMessage(session);
			message.addRecipient(Message.RecipientType.TO, new InternetAddress(to));
			message.setSubject(sub);
			message.setText(msg);
			// send message
			Transport.send(message);
			System.out.println("message sent successfully");
		} catch (MessagingException e) {
			throw new RuntimeException(e);
		}
	}
}
