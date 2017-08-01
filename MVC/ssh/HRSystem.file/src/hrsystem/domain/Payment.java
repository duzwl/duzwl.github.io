package hrsystem.domain;

import java.io.Serializable;

public class Payment
	implements Serializable
{
	private static final long serialVersionUID = 48L;
	private Integer id;
	private String payMonth;
	private double amount;
	private Employee employee;
	
	public Payment() {}

	public Payment(Integer id, String payMonth, 
		double amount, Employee employee)
	{
		this.id = id;
		this.payMonth = payMonth;
		this.amount = amount;
		this.employee = employee;
	}

	public void setId(Integer id)
	{
		this.id = id;
	}
	public Integer getId()
	{
		return this.id;
	}

	public void setPayMonth(String payMonth)
	{
		this.payMonth = payMonth;
	}
	public String getPayMonth()
	{
		return this.payMonth;
	}

	public void setAmount(double amount)
	{
		this.amount = amount;
	}
	public double getAmount()
	{
		return this.amount;
	}

	public void setEmployee(Employee employee)
	{
		this.employee = employee;
	}
	public Employee getEmployee()
	{
		return this.employee;
	}
}
