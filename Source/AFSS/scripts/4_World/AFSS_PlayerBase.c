modded class PlayerBase extends ManBase
{
	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
	{
		if (rpc_type == -77777)
		{
			Param3<bool, int, int> afssParams;

			if (!ctx.Read(afssParams))
			{
				return;
			}

			bool isAutoForward = afssParams.param1;
			int autoForwardSpeed = afssParams.param2;
			int autoForwardAngle = afssParams.param3;

			GetInputController().OverrideMovementSpeed(isAutoForward, autoForwardSpeed);
			GetInputController().OverrideMovementAngle(isAutoForward, autoForwardAngle);
		}

		super.OnRPC(sender, rpc_type, ctx);
	}
}
