include "test/scripting/stable_save.lua"

-- Test saveloading of input queues
run(function()

   local function assert_all_queues_are_full(building)
      local inputs = building:get_inputs("all")
      for name, amount in pairs(building.valid_inputs) do
         assert_equal(amount, inputs[name])
      end
   end

   local function assert_all_queues_are_empty(building)
      local inputs = building:get_inputs("all")
      for name, amount in pairs(building.valid_inputs) do
         assert_equal(0, inputs[name])
      end
   end

   sleep(8000)

   local b = p1:place_building("barbarians_barracks", map:get_field(25, 25), false, true)

   assert_all_queues_are_empty(b)

   b:set_inputs(b.valid_inputs)
   b:set_workers(b.valid_workers)

   sleep(18000)
   assert_all_queues_are_full(b)

   stable_save(game, "inputqueues")
   sleep(8000)

   assert_all_queues_are_full(b)

   print("# All Tests passed.")
   wl.ui.MapView():close()
end)
