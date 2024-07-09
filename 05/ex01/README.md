이제 관료들이 할 일을 줍시다. 서류 더미를 작성하는 것보다 더 좋은 활동이 무엇이겠습니까?

그럼 Form 클래스를 만들겠습니다. 이 클래스는 다음과 같은 속성을 가집니다:
• 상수 이름.
• 서명 여부를 나타내는 부울 값 (생성 시에는 서명되지 않음).
• 서명에 필요한 상수 등급.
• 실행에 필요한 상수 등급.

이 모든 속성은 private로 지정되어 있으며, protected는 아닙니다.

Form의 등급은 Bureaucrat에 적용되는 동일한 규칙을 따릅니다. 따라서, 양식 등급이 범위를 벗어나면 다음과 같은 예외가 발생합니다:
Form::GradeTooHighException 및 Form::GradeTooLowException.

이전과 마찬가지로 모든 속성에 대한 게터(getters)와 모든 양식의 정보를 출력하는 삽입(«) 연산자 오버로드를 작성하세요.

또한 Bureaucrat을 매개변수로 받는 beSigned() 멤버 함수를 Form에 추가하세요. 관료의 등급이 충분히 높으면(필요한 등급보다 높거나 같으면) 양식 상태를 서명으로 변경합니다. 등급이 너무 낮으면 Form::GradeTooLowException을 던지세요.

마지막으로, Bureaucrat에 signForm() 멤버 함수를 추가하세요. 양식이 서명되면 다음과 같은 메시지를 출력합니다:
<bureaucrat> signed <form>
그렇지 않으면 다음과 같은 메시지를 출력합니다:
<bureaucrat> couldn’t sign <form> because <reason>.

모든 것이 예상대로 작동하는지 확인하기 위해 테스트를 구현하고 제출하세요.
