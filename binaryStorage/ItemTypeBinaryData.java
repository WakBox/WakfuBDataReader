package com.ankamagames.wakfu.client.binaryStorage;

public class ItemTypeBinaryData implements dEZ {
    protected short aKG;
    protected short aKI;
    protected boolean hHB;
    protected boolean hHC;
    protected boolean hHD;
    protected String[] hHE;
    protected String[] hHF;
    protected short hHG;
    protected int[] hHH;
    
    public ItemTypeBinaryData()
    {
        super();
    }
    
    public short nJ()
    {
        int i = this.aKG;
        return (short)i;
    }
    
    public short nK()
    {
        int i = this.aKI;
        return (short)i;
    }
    
    public boolean nT()
    {
        return this.hHB;
    }
    
    public boolean nR()
    {
        return this.hHC;
    }
    
    public boolean nS()
    {
        return this.hHD;
    }
    
    public String[] ckn()
    {
        return this.hHE;
    }
    
    public String[] cko()
    {
        return this.hHF;
    }
    
    public short ckp()
    {
        int i = this.hHG;
        return (short)i;
    }
    
    public int[] ckq()
    {
        return this.hHH;
    }
    
    public void reset()
    {
        this.aKG = (short)0;
        this.aKI = (short)0;
        this.hHB = false;
        this.hHC = false;
        this.hHD = false;
        this.hHE = null;
        this.hHF = null;
        this.hHG = (short)0;
        this.hHH = null;
    }
    
    public void a(ceb a)
    {
        int i = a.getShort();
        this.aKG = (short)i;
        int i0 = a.getShort();
        this.aKI = (short)i0;
        this.hHB = a.readBoolean();
        this.hHC = a.readBoolean();
        this.hHD = a.readBoolean();
        this.hHE = a.cll();
        this.hHF = a.cll();
        int i1 = a.getShort();
        this.hHG = (short)i1;
        this.hHH = a.cli();
    }
    
    final public int gZ()
    {
        return aPw.eEa.getId();
    }
}