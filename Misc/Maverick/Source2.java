

class InvalidEmailException extends Exception{
    public InvalidEmailException(String s)
        {
            super(s);
        }
}

class InvalidPasswordException extends Exception{
    public InvalidPasswordException(String s)
        {
            super(s);
        }
}

class PasswordNotMatchException extends Exception{
    public PasswordNotMatchException(String s)
        {
            super(s);
        }
}

class Register{
    public String checkCredentials(String email, String pass, String cpass) throws Exception{
        try{
            if(!(email.contains(".") && email.contains("@"))){
                throw new InvalidEmailException("Invalid Email");
            }
        }catch (InvalidEmailException e){
            return e.getMessage();
        }
        try{
            if(pass.length() < 6){
                throw new InvalidPasswordException("Invalid Password");
            }
        }catch (InvalidPasswordException e){
            return e.getMessage();
        }
        try{
            if(cpass.compareTo(pass) != 0){
                throw new PasswordNotMatchException("Password not match");
            }
        }catch (PasswordNotMatchException e){
            return e.getMessage();
        }

        return "Registered";
    }
}

public class Source2 {
        public static void main(String[] args) throws Exception {
            String email1 = "myemail@email";
            String email2 = "myemail@email.com";
            String pass = "pass1234";
            String cpass = "pass1234";

            Register user = new Register();
            String ans1 = user.checkCredentials(email1, pass, cpass);
            String ans2 = user.checkCredentials(email2, pass, cpass);

            System.out.println(ans1);
            System.out.println(ans2);
        }
}
