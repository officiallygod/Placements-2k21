import java.util.ArrayList;
import java.util.List;

class Customer{
    public String customerName;
    public int amount;
    public int time;
    public int creditScore;

    Customer(String customerName, int creditScore, int amount, int time){
        this.customerName = customerName;
        this.amount = amount;
        this.time = time;
        this.creditScore = creditScore;
    }
}

class Bank{
    int rate = 10;
    public List<Customer> bankCustomers = new ArrayList<Customer>();
    public List<Customer> merchantCustomers = new ArrayList<Customer>();

    String addCustomer(Customer customer)
    {
        if(customer.creditScore < customer.amount * customer.time * 100){
            bankCustomers.add(customer);
            return ("Added to Bank");
        }else
        {
            merchantCustomers.add(customer);
            return ("Added to Merchant");
        }
        
    }
    int subtractAmount(String data)
    {
        return 0;
    }
}

public class Source{
        public static void main(String[] args) {
        Bank bank = new Bank();
        Customer cst = new Customer("A", 2000, 50000, 2);
        String ans = bank.addCustomer(cst);
        System.out.println(ans);
    }
}
