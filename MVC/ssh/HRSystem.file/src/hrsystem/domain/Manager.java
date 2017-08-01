package hrsystem.domain;

import java.io.Serializable;
import java.util.*;

public class Manager
	extends Employee implements Serializable
{
	private static final long serialVersionUID = 48L;
	private String dept;
	
	// 该经理管理的所有员工
	private Set<Employee> employees = new HashSet<Employee>();
	// 该经理签署的所有批复
	private Set<CheckBack> checks = new HashSet<CheckBack>();
	
	public Manager() {}
	
	public Manager(String dept, Set<Employee> employees, Set<CheckBack> checks)
	{
		this.dept = dept;
		this.employees = employees;
		this.checks = checks;
	}
	
	public void setDept(String dept)
	{
		this.dept = dept;
	}
	public String getDept()
	{
		return this.dept;
	}
	
	public void setEmployees(Set<Employee> employees)
	{
		this.employees = employees;
	}
	public Set<Employee> getEmployees()
	{
		return this.employees;
	}
	
	public void setChecks(Set<CheckBack> checks)
	{
		this.checks = checks;
	}
	public Set<CheckBack> getChecks()
	{
		return this.checks;
	}
}
