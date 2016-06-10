#import "HUBComponent.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Extended Hub component protocol that adds the ability to save & restore UI state
 *
 *  Use this protocol if your component has some UI state that should be persisted between
 *  reuses. Examples of this might be selection state, internal scrolling positions, etc.
 *
 *  The Hub Framework automatically manages the state for you, and will ask the component
 *  to provide its current UI state, and to restore a previously saved state whenever
 *  appropriate. UI states are always stored based on `HUBComponentModel` identifiers, so the
 *  same UI state will never be reused for diffrent models, although it might be reused
 *  for different component implementations. UI state is never shared across different views.
 *
 *  For more information, see `HUBComponent`.
 */
@protocol HUBComponentWithRestorableUIState <HUBComponent>

/**
 *  Return the current UI state of the component
 *
 *  You can use any type to represent your component's UI state, as long as you keep it consitent
 *  between this method and `restoreUIState:`. The Hub Framework will automatically call this method
 *  before a component is reused, to save the current state for when the next time a component will
 *  render the `HUBComponentModel` that this component is currently rendering.
 *
 *  Returning `nil` from this method makes the Hub Framework remove any previously saved state for
 *  the current `HUBComponentModel`.
 */
- (nullable id)currentUIState;

/**
 *  Restore a previously saved UI state
 *
 *  @param state The previously saved state that should now be restored. This object will be of the
 *  same type as was returned from `currentUIState`.
 *
 *  The Hub Framework will automatically call this method whenever the component will start rendering
 *  a `HUBComponentModel` for which a UI state was previously saved. This method will be called after
 *  the component was sent `configureViewWithModel:`, before the component is about to appear on the
 *  screen.
 */
- (void)restoreUIState:(id)state;

@end

NS_ASSUME_NONNULL_END
