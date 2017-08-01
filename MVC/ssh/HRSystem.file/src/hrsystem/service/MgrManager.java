package hrsystem.service;

import hrsystem.vo.*;
import hrsystem.domain.*;
import hrsystem.exception.*;

import java.util.*;

public interface MgrManager
{

	void addEmp(Employee emp , String mgr) throws HrException;


	// ���ݾ��������еĲ����ϸ��¹���
	List<SalaryBean> getSalaryByMgr(String mgr) throws HrException;

	// ���ݾ����ظò��ŵ�ȫ��Ա��
	List<EmpBean> getEmpsByMgr(String mgr) throws HrException;

	// ���ݾ����ظò��ŵ�û������������
	List<AppBean> getAppsByMgr(String mgr) throws HrException;

	// ��������
	void check(int appid, String mgrName, boolean result);
}
