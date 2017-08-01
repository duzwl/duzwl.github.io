package hrsystem.service;

import hrsystem.vo.*;
import hrsystem.domain.*;
import hrsystem.exception.*;

import java.util.*;

public interface MgrManager
{

	void addEmp(Employee emp , String mgr) throws HrException;


	// 根据经理返回所有的部门上个月工资
	List<SalaryBean> getSalaryByMgr(String mgr) throws HrException;

	// 根据经理返回该部门的全部员工
	List<EmpBean> getEmpsByMgr(String mgr) throws HrException;

	// 根据经理返回该部门的没有批复的申请
	List<AppBean> getAppsByMgr(String mgr) throws HrException;

	// 处理申请
	void check(int appid, String mgrName, boolean result);
}
