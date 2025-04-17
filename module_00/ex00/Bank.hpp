#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include <vector>

class Bank {
   public:
    struct Account {
       private:
        std::size_t _id;
        float _value;

        Account(int id, int value);
        ~Account(void);

        friend class Bank;

       public:
        int getId(void) const;
        int getValue(void) const;
    };
    Bank(void);
    Bank(Bank const &src);
    ~Bank(void);

    Account *createAccount(int value);
    const Account &operator[](std::size_t id) const;
    void deleteAccount(std::size_t id);
    void deposit(int id, int amount);
    void withdraw(int id, int amount);
    float getLiquidity(void) const;
    void loan(Account *account, int amount);
    std::vector<Bank::Account *> getAccounts(void) const;

   private:
    float _liquidity;
    std::vector<Bank::Account *> _accounts;
    static int _accountId;
    static const float _fee;
};

std::ostream &operator<<(std::ostream &out, const Bank::Account &account);
std::ostream &operator<<(std::ostream &out, Bank const &bank);

#endif
