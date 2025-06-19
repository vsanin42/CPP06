/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Classes.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanin <vsanin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 18:46:45 by vsanin            #+#    #+#             */
/*   Updated: 2025/06/19 18:51:43 by vsanin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSES_HPP
#define CLASSES_HPP

class Base
{
    public:
        virtual ~Base();
};

class A : public Base
{
	private:
	public:
};

class B : public Base
{
	private:
	public:
};

class C : public Base
{
	private:
	public:
};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif

