#include <bits/stdc++.h>
using namespace std;

std::mutex muA;
std::mutex muB;

void CallHome_AB(string message) {
  muA.lock();
  //Some additional processing
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  muB.lock();
  cout << "Thread " << this_thread::get_id() << " says " << message << endl;
  muB.unlock();
  muA.unlock();
}

void CallHome_BA(string message) {
  muB.lock();
  //Some additional processing
  std::this_thread::sleep_for(std::chrono::milliseconds(100));
  muA.lock();
  cout << "Thread " << this_thread::get_id() << " says " << message << endl;
  muA.unlock();
  muB.unlock();
}

/* Reference Count: A simple class for maanging the number of active smart pointers*/
class ReferenceCount {
private:
  int m_RefCount{ 0 };
public:
  void Increment() {
    ++m_RefCount;
  }
  int Decrement()
  {
    return --m_RefCount;
  }
  int GetCount() const
  {
    return m_RefCount;
  }
};

template <typename T>
class smart_ptr
{
private:
  T* m_Object{ nullptr };
  ReferenceCount* m_ReferenceCount{ nullptr };
public:
  smart_ptr()
  {
  }
  //Constructor
  smart_ptr(T* object)
    : m_Object{ object }
    , m_ReferenceCount{ new ReferenceCount() }
  {
    m_ReferenceCount->Increment();
    cout << "Created smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << endl;
  }
  //Destructor
  virtual ~smart_ptr()
  {
    if (m_ReferenceCount)
    {
      int decrementedCount = m_ReferenceCount->Decrement();
      cout << "Destroyed smart_ptr! Ref count is " << decrementedCount << endl;
      if (decrementedCount <= 0)
      {
        delete m_ReferenceCount;
        delete m_Object;
        m_ReferenceCount = nullptr;
        m_Object = nullptr;
      }
    }
  }
  // Copy Constructor
  smart_ptr(const smart_ptr<T>& other)
    : m_Object{ other.m_Object }
    , m_ReferenceCount{ other.m_ReferenceCount }
  {
    m_ReferenceCount->Increment();
    cout << "Copied smart_ptr! Ref count is "
         << m_ReferenceCount->GetCount() << endl;
  }
  // Overloaded Assignment Operator
  smart_ptr<T>& operator=(const smart_ptr<T>& other)
  {

    if (this != &other)
    {
      if (m_ReferenceCount && m_ReferenceCount->Decrement() == 0)
      {
        delete m_ReferenceCount;
        delete m_Object;
      }
      m_Object = other.m_Object;
      m_ReferenceCount = other.m_ReferenceCount;
      m_ReferenceCount->Increment();

    }
    cout << "Assigning smart_ptr! Ref count is " << m_ReferenceCount->GetCount() << endl;
    return *this;
  }
  //Dereference operator
  T& operator*()
  {
    return *m_Object;
  }
  //Member Access operator
  T* operator->()
  {
    return m_Object;
  }
};
class AirCraft
{
private:
  std::string m_Model;
public:
  AirCraft() : m_Model("Generic Model")
  {
    cout << "Generic model aircraft created" << endl;
  }
  AirCraft(const string& modelName) : m_Model(modelName)
  {
    cout << "Aircraft type" << m_Model << "is created!" << endl;
  }
  void SetAirCraftModel(const string& modelName)
  {
    cout << "Aircraft model changed from  " << m_Model << " to " << modelName << endl;
    m_Model = modelName;
  }
  ~AirCraft()
  {
    cout << "Destroying Aircraft of model:" << m_Model << "!" << endl;
  }
};
void LaunchRocket()
{
  cout << "Launching Rocket" << endl;
}
int main()
{

  // Thread Test 1
  // thread t2(CallHome_AB, "Hello from Jupiter");
  // thread t3(CallHome_BA, "Hello from Pluto");

  // t2.join();
  // t3.join();


  // Custom Smart Pointer Test
  smart_ptr<AirCraft> raptorPointer(new AirCraft("F-22 Raptor"));
  raptorPointer->SetAirCraftModel("B2 Bomber");
  (*raptorPointer).SetAirCraftModel("B2 Spirit");
  smart_ptr<AirCraft> hornettPointer(new AirCraft("F-14 Hornett"));
  raptorPointer = hornettPointer;
  thread t1(LaunchRocket);
  t1.join();

  cout << "All Done" << endl;
  return 0;
}
