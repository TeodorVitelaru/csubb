package com.example.exam.repo;

import com.example.exam.domain.Page;
import com.example.exam.domain.Pageable;
import com.example.exam.domain.Show;

public interface PaginingRepository {
    Page<Show> findAllOnPage(Pageable pageable, int flag);

}
