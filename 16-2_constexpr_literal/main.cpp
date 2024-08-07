//constexpr 의 내부에서는 리터럴 타입의 변수만 정의할 수 있다.


//리터럴 		- 컴파일 타임에 정의할 수 있는 타입.
//void
//scalar - int, double, char, bool 등등
//reference 타입
//리터럴 타입의 배열
//아래 조건 만족
//	- 디폴트 소멸자를 가짐.
//		1. 람다함수
//		2. Aggregate 타입 (사용자 정의 생성/소멸자가 없음. 모든 멤버 데이터들이 public.)
//		3. constexpr 생성자를 가짐. , 복사/이동 생성자가 없음.


//constexpr 로 정의된 함수는,
//"컴파일타임에 정의된 인자를 입력받으면, 출력또한 컴파일타임에 보장하겠다" 로 이해해도 된다.
//컴파일 타임에 정의되지 않는 인자를 받더라도, 런타임에 함수를 실행하게 된다.

#include <iostream>

constexpr int factorial_c(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N * factorial_c(N - 1);
    }
}

int main()
{	int n = 10; // 런타임 정의
    const int m = 10; // 런타임에 정의될 수도, 컴파일 타임에 정의될 수도 있다.
    constexpr int k = 10; //  컴파일 타임에 정의.

    auto start = std::chrono::high_resolution_clock::now();
    std::cout << factorial_c(n) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << factorial_c(m) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << factorial_c(k) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration.count() << std::endl;

    return 0;
}
