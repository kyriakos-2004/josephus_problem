#include <iostream>
#include <string>

static constexpr long long
LastManStanding(long long n, long long s = 0) noexcept
{
    long long i = s + 1;
    for (long long x = i; x <= n; x++, i++)
    {
        s = (s + 2) % i;
    }

    return s + 1;
}

static long long
BitShiftingSurvivor(long long number) noexcept
{
    auto binary = std::string{};
    while (number != 0)
    {
        binary = (number % 2 == 0 ? "0" : "1") + binary;
        number /= 2;
    }

    std::cout << "Binary before: " << binary << std::endl;
    char first = binary.front();
    binary.erase(0, 1);
    binary += first;
    std::cout << "Binary after: " << binary << std::endl;

    long long surviving_position = std::stoll(binary, nullptr, 2);

    return surviving_position;
}


int main()
{
    long long number;
    std::cout << "Number of soldiers: ";
    if (!(std::cin >> number))
    {
        std::cerr << "Invalid input. Exiting...";
        return 1;
    }

    auto original_number = number;
    std::cout << "1st way with observational mathematics" << std::endl;
    std::cout << "Survivor position: " << LastManStanding(number) << std::endl;
    std::cout << "=============================================" << std::endl;
    
    std::cout << "2nd way by shifting the most significant bit" << std::endl;
    number = original_number;
    auto survivor = BitShiftingSurvivor(number);
    std::cout << "Survivor position: " << survivor;

    return 0;
}
