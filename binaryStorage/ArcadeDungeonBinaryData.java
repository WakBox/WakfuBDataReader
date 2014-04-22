package com.ankamagames.wakfu.client.binaryStorage;

public class ArcadeDungeonBinaryData implements dEZ {
    protected int az;
    protected short aC;
    protected H[] mwL;
    protected bX[] mwM;
    protected fW[] mwN;
    protected int mwO;
    protected int mwP;
    
    public ArcadeDungeonBinaryData()
    {
        super();
    }
    
    public int getId()
    {
        return this.az;
    }
    
    public short D()
    {
        int i = this.aC;
        return (short)i;
    }
    
    public H[] dvn()
    {
        return this.mwL;
    }
    
    public bX[] dvo()
    {
        return this.mwM;
    }
    
    public fW[] dvp()
    {
        return this.mwN;
    }
    
    public int dvq()
    {
        return this.mwO;
    }
    
    public int dvr()
    {
        return this.mwP;
    }
    
    public void reset()
    {
        this.az = 0;
        this.aC = (short)0;
        this.mwL = null;
        this.mwM = null;
        this.mwN = null;
        this.mwO = 0;
        this.mwP = 0;
    }
    
    public void a(ceb a)
    {
        this.az = a.getInt();
        int i = a.getShort();
        this.aC = (short)i;
        int i0 = a.getInt();
        this.mwL = new H[i0];
        int i1 = 0;
        while(i1 < i0)
        {
            this.mwL[i1] = new H();
            this.mwL[i1].a(a);
            i1 = i1 + 1;
        }
        int i2 = a.getInt();
        this.mwM = new bX[i2];
        int i3 = 0;
        while(i3 < i2)
        {
            this.mwM[i3] = new bX();
            this.mwM[i3].a(a);
            i3 = i3 + 1;
        }
        int i4 = a.getInt();
        this.mwN = new fW[i4];
        int i5 = 0;
        while(i5 < i4)
        {
            this.mwN[i5] = new fW();
            this.mwN[i5].a(a);
            i5 = i5 + 1;
        }
        this.mwO = a.getInt();
        this.mwP = a.getInt();
    }
    
    final public int gZ()
    {
        return aPw.eEY.getId();
    }
}