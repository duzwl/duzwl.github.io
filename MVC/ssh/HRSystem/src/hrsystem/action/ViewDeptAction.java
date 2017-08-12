package hrsystem.action;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

import com.opensymphony.xwork2.*;
import org.apache.struts2.interceptor.*;

import hrsystem.service.MgrManager;
import hrsystem.exception.HrException;
import hrsystem.action.base.MgrBaseAction;
import hrsystem.vo.*;

import java.util.List;

public class ViewDeptAction extends MgrBaseAction
{
	// 封装发薪列表的List属性
	private List sals;
	
	// sals属性的setter和getter方法
	public void setSals(List sals)
	{
		this.sals = sals;
	}
	public List getSals()
	{
		return this.sals;
	}	

	public String execute()
		throws Exception
	{
		// 创建ActionContext实例
		ActionContext ctx = ActionContext.getContext();
		// 获取HttpSession中的user属性
		String mgrName = (String)ctx.getSession()
			.get(WebConstant.USER);
		// 调用业务逻辑方法取得当前员工的全部发薪列表
		List<SalaryBean> result = mgr.getSalaryByMgr(mgrName);
		System.out.println("--------------" + result);
		setSals(result);
		return SUCCESS;
	}
}
