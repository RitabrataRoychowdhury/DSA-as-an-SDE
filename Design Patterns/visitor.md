# Visitor Pattern – Real-World Spring Boot Example

## 🧠 Overview
The Visitor Pattern lets you add new operations to existing class hierarchies without changing their structure. It's ideal when:

- You have a fixed set of classes (e.g., different event types).
- You want to add new behaviors over them (e.g., logging, analytics) without modifying those classes.

### ✅ Follows Open/Closed Principle
Open for extension, closed for modification.

### ⚠️ Trade-off
Adding new element types means updating all visitors.

## 🔧 Real-Life Backend Use Case: Event Processing in Spring Boot

### 🎯 Goal
Process different event types (e.g., user registration, payment, shipping) with multiple behaviors:

- Logging
- Analytics
- Notifications

...without duplicating code or bloating event classes.

## 🧩 Structure

### 1. Event Element Interface

1. Event Element Interface
java
Copy
Edit
public interface Event {
    void accept(EventVisitor visitor);
}
2. Concrete Event Types
java
Copy
Edit
public class UserRegistered implements Event {
    // fields: username, email, etc.
    public void accept(EventVisitor v) { v.visit(this); }
}

public class PaymentProcessed implements Event {
    // fields: amount, paymentId, etc.
    public void accept(EventVisitor v) { v.visit(this); }
}
3. Visitor Interface
java
Copy
Edit
public interface EventVisitor {
    void visit(UserRegistered e);
    void visit(PaymentProcessed e);
    // Add more visit methods for new event types
}
4. Concrete Visitors (Behaviors)
java
Copy
Edit
@Component
public class LoggingVisitor implements EventVisitor {
    public void visit(UserRegistered e) {
        log.info("User registered: {}", e.getUsername());
    }
    public void visit(PaymentProcessed e) {
        log.info("Payment: {}", e.getAmount());
    }
}
java
Copy
Edit
@Component
public class AnalyticsVisitor implements EventVisitor {
    public void visit(UserRegistered e) {
        analytics.trackUserSignup(e.getUsername());
    }
    public void visit(PaymentProcessed e) {
        analytics.trackRevenue(e.getAmount());
    }
}
5. Event Processor Service
java
Copy
Edit
@Service
@RequiredArgsConstructor
public class EventProcessingService {
    private final List<EventVisitor> visitors;

    public void process(Event event) {
        for (EventVisitor visitor : visitors) {
            event.accept(visitor);
        }
    }
}
6. REST Controller
java
Copy
Edit
@RestController
@RequiredArgsConstructor
public class EventController {
    private final EventProcessingService service;

    @PostMapping("/events")
    public ResponseEntity<Void> handleEvent(@RequestBody EventDTO dto) {
        Event event = dto.toDomain(); // Converts DTO to Event subclass
        service.process(event);
        return ResponseEntity.accepted().build();
    }
}
✅ Benefits
Modular Behaviors: Add new actions via new visitors.

Clean Event Classes: No behavioral logic inside event types.

Easily Testable: Visitors are isolated and independently testable.

Scalable: Extend functionality without modifying core domain logic.

⚠️ Trade-Offs
Every new Event type requires updating all visitors.

Slightly more boilerplate if there are many event types.

