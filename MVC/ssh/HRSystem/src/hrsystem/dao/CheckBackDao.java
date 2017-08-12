package hrsystem.dao;

import java.util.*; 

import hrsystem.domain.*;

public interface CheckBackDao
{

	CheckBack get(Integer id);
	Integer save(CheckBack checkBack);
	void update(CheckBack checkBack);
	void delete(CheckBack checkBack);
	void delete(Integer id);
	List<CheckBack> findAll();
}
