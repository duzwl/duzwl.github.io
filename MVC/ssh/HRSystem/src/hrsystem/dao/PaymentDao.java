package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface PaymentDao
{

	Payment get(Integer id);
	Integer save(Payment payment);
	void update(Payment payment);
	void delete(Payment payment);
	void delete(Integer id);
	List<Payment> findAll();
	List<Payment> findByEmp(Employee emp);
	Payment findByMonthAndEmp(String payMonth , Employee emp);
}
